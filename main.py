SAVE_FN = "main.c"
with open("template_main.c", "r") as f:
    PROGRAM_TEMPLATE = f.read()

# IF_TEMPLATE = """
#     if (n1d1 == '{}' && n1d2 == '{}' && op == '{}' && n2d1 == '{}' && n2d2 == '{}') {
#         strncpy(result, "{}", {});
#     }
# """ 

def create_if(*args):
    expression = "n1d1 == '{}' && n1d2 == '{}' && op == '{}' && n2d1 == '{}' && n2d2 == '{}'".format(*args[:5])
    body = 'strncpy(result, "{}", {});'.format(*args[5:])

    return "    if (" + expression + ") {\n" + "        " + body + "\n    }"

def main():
    digits = [str(i) for i in range(0, 10)]

    operators = ['+', '-', '/', 'x']
    actual_operations = {
        '+': lambda x, y: x + y,
        '-': lambda x, y: x - y,
        '/': lambda x, y: x / y,
        'x': lambda x, y: x * y
    }
    
    ifs = []
    for n1d1 in digits:
        for n1d2 in digits:
            for op in operators:
                for n2d1 in digits:
                    for n2d2 in digits:
                        n1 = int(n1d1 + n1d2)
                        n2 = int(n2d1 + n2d2)

                        try:
                            result = actual_operations[op](n1, n2)
                        except ZeroDivisionError:
                            result = "undefined"
                        ifs.append(create_if(n1d1,n1d2,op,n2d1,n2d2,result, len(str(result))))

    ifs.sort()
    
    program = PROGRAM_TEMPLATE.replace("{!!}",'\n\n'.join(ifs))

    with open(SAVE_FN, "w") as f:
        f.write(program)


if __name__ == "__main__":
    main()