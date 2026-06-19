#!/usr/bin/env python3
"""Port of camx/build/infrastructure/tools/props.pl
Generates g_camxproperties.h and g_camxproperties.cpp from camxproperties.xml"""

import sys
import xml.etree.ElementTree as ET

def main():
    if len(sys.argv) < 3:
        print(f"Usage: {sys.argv[0]} <input.xml> <output_base>", file=sys.stderr)
        sys.exit(1)

    input_path = sys.argv[1]
    output_base = sys.argv[2]

    tree = ET.parse(input_path)
    root = tree.getroot()

    sections = ['MainProperty', 'InternalProperty', 'UsecaseProperty', 'DebugDataProperty']
    begins = {
        'MainProperty':      'PropertyIDPerFrameResultBegin',
        'InternalProperty':  'PropertyIDPerFrameInternalBegin',
        'UsecaseProperty':   'PropertyIDUsecaseBegin',
        'DebugDataProperty': 'PropertyIDPerFrameDebugDataBegin',
    }
    node_complete_count = 32
    link_metadata_count = 20

    props = {}
    for sec in sections:
        elem = root.find(sec)
        props[sec] = []
        if elem is not None:
            for p in elem.findall('Property'):
                props[sec].append({'Name': p.get('Name'), 'Type': p.get('Type')})

    for i in range(node_complete_count):
        props['MainProperty'].append({'Name': f'NodeComplete{i}', 'Type': 'BOOL'})
    for i in range(link_metadata_count):
        props['MainProperty'].append({'Name': f'LinkMetadata{i}', 'Type': 'INT'})

    copyright = (
        "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n"
        "// Copyright (c) 2018-2019 Qualcomm Technologies, Inc.\n"
        "// All Rights Reserved.\n"
        "// Confidential and Proprietary - Qualcomm Technologies, Inc.\n"
        "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n"
    )

    h_lines = []
    c_lines = []

    h_lines.append(copyright)
    h_lines.append(
        "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n"
        "/// @file g_camxproperties.h\n"
        "/// @brief Define Qualcomm Technologies, Inc. Property IDs and structures\n"
        "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n"
        "\n"
        "#ifndef G_CAMXPROPERTIES_H\n"
        "#define G_CAMXPROPERTIES_H\n"
        "\n"
        "#include \"camxdefs.h\"\n"
        "\n"
        "CAMX_NAMESPACE_BEGIN\n"
        "\n"
        "\n"
        "\n"
        f"// {node_complete_count} Properties reserved for tracking dependencies on the previous request\n"
        "// Use Node->GetNodeCompleteProperty() to identify the prop\n"
        f"static const UINT NodeCompleteCount = {node_complete_count};\n"
        "\n"
        f"// {link_metadata_count} Properties reserved for tracking link based metadata\n"
        f"static const UINT LinkMetadataCount = {link_metadata_count};\n"
    )

    c_lines.append(copyright)
    c_lines.append(
        "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n"
        "/// @file g_camxproperties.cpp\n"
        "/// @brief Define Qualcomm Technologies, Inc. Property IDs and structures\n"
        "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n"
        "\n"
        "#include \"camxincs.h\"\n"
        "#include \"camxpropertyblob.h\"\n"
        "\n"
        "CAMX_NAMESPACE_BEGIN\n"
        "\n"
    )

    for sec in sections:
        prop_list = props[sec]
        begin = begins[sec]
        end = begin.replace('Begin', 'End')
        blobname = sec + 'Blob'
        count = len(prop_list)

        h_lines.append(f"\n/* Beginning of {sec} */\n\n")

        c_lines.append(f"/// @brief LUT that allows using the propertyID to determine a string name for the propertyID\n")
        c_lines.append(f"///        Indexed with (id & ~PropertyIDPerFrameDebugDataBegin)\n")
        c_lines.append(f"const CHAR* p{sec}Strings[{count}] =\n{{\n")

        lut = f"\n/// @brief LUT of each member in the property blob\nstatic const PropertyID {sec}LinearLUT[] =\n{{\n"
        blob = f"\n/// @brief Collection of properties in a struct\nstruct {blobname}\n{{\n"
        offsets = f"\n/// @brief Offsets of each member in the property blob\nstatic const SIZE_T {sec}Offsets[] =\n{{\n"
        sizes = f"\n/// @brief Sizes of each member in the property blob\nstatic const SIZE_T {sec}Sizes[] =\n{{\n"

        for i, prop in enumerate(prop_list):
            name = prop['Name']
            typ = prop['Type']
            member = f"p{name}" if '*' in typ else f"m{name}"

            h_lines.append(f"static const PropertyID PropertyID{name:<35s} = {begin} + 0x{i:02X};\n")
            c_lines.append(f"    \"PropertyID{name}\",\n")
            lut += f"    PropertyID{name},\n"
            blob += f"    {typ:<35s} {member + ';':<35s}///< {name}\n"
            offsets += f"    offsetof({blobname}, {member}),\n"
            sizes += f"    sizeof({typ}),\n"

        c_lines.append("};\n\n")

        h_lines.append(f"\nextern const CHAR* p{sec}Strings[{count}];\n")
        h_lines.append(f"\nstatic const PropertyID {end} = {begin} + 0x{count - 1:02X};\n")
        h_lines.append(lut + "};\n")
        h_lines.append(blob + "};\n")
        h_lines.append(offsets + "};\n")
        h_lines.append(sizes + "};\n")
        h_lines.append(f"\n/* End of {sec} */\n\n")

    h_lines.append("CAMX_NAMESPACE_END\n#endif // G_CAMXPROPERTIES_H\n")
    c_lines.append("CAMX_NAMESPACE_END\n")

    with open(output_base + '.h', 'w') as f:
        f.write(''.join(h_lines))
    with open(output_base + '.cpp', 'w') as f:
        f.write(''.join(c_lines))

    print(f"Generated {output_base}.h ({count} properties in last section)")
    print(f"Generated {output_base}.cpp")

if __name__ == '__main__':
    main()
