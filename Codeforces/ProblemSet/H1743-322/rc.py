#!/usr/bin/env python3
import sys

def remove_comments(code: str) -> str:
    """
    Remove C++ style comments (both // and /* */) from the code.
    This function uses a simple state machine that carefully handles string
    and character literals so that comment-like text inside them is preserved.
    """
    result = []
    i = 0
    state = "NORMAL"  # States: NORMAL, LINE_COMMENT, BLOCK_COMMENT, STRING, CHAR

    while i < len(code):
        if state == "NORMAL":
            if code[i:i+2] == "//":
                state = "LINE_COMMENT"
                i += 2
            elif code[i:i+2] == "/*":
                state = "BLOCK_COMMENT"
                i += 2
            elif code[i] == '"':
                result.append(code[i])
                state = "STRING"
                i += 1
            elif code[i] == "'":
                result.append(code[i])
                state = "CHAR"
                i += 1
            else:
                result.append(code[i])
                i += 1

        elif state == "LINE_COMMENT":
            # Skip until the end of the line
            if code[i] == "\n":
                result.append("\n")
                state = "NORMAL"
            i += 1

        elif state == "BLOCK_COMMENT":
            # Skip until the end of the block comment
            if code[i:i+2] == "*/":
                state = "NORMAL"
                i += 2
            else:
                # If there's a newline inside a block comment, output it so we
                # keep line numbering roughly correct.
                if code[i] == "\n":
                    result.append("\n")
                i += 1

        elif state == "STRING":
            if code[i] == "\\" and i + 1 < len(code):
                result.append(code[i])
                result.append(code[i+1])
                i += 2
            elif code[i] == '"':
                result.append(code[i])
                state = "NORMAL"
                i += 1
            else:
                result.append(code[i])
                i += 1

        elif state == "CHAR":
            if code[i] == "\\" and i + 1 < len(code):
                result.append(code[i])
                result.append(code[i+1])
                i += 2
            elif code[i] == "'":
                result.append(code[i])
                state = "NORMAL"
                i += 1
            else:
                result.append(code[i])
                i += 1

    return "".join(result)

def remove_empty_lines(code: str) -> str:
    """
    Remove lines that are empty or contain only whitespace.
    This is used to delete lines that were full comments.
    """
    lines = code.splitlines()
    # Keep lines that are not empty after stripping whitespace
    filtered_lines = [line for line in lines if line.strip() != ""]
    return "\n".join(filtered_lines)

def main():
    if len(sys.argv) < 2:
        print("Usage: python remove_comments.py <input_file> [output_file]")
        sys.exit(1)

    input_file = sys.argv[1]
    output_file = sys.argv[2] if len(sys.argv) >= 3 else input_file

    try:
        with open(input_file, 'r', encoding='utf-8') as f:
            code = f.read()
    except IOError as e:
        print(f"Error reading file {input_file}: {e}")
        sys.exit(1)

    # Remove comments
    cleaned_code = remove_comments(code)
    # Remove lines that become empty after comment removal
    final_code = remove_empty_lines(cleaned_code)

    if output_file:
        try:
            with open(output_file, 'w', encoding='utf-8') as f:
                f.write(final_code)
        except IOError as e:
            print(f"Error writing to file {output_file}: {e}")
            sys.exit(1)
    else:
        print(final_code)

if __name__ == "__main__":
    main()
