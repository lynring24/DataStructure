print("Postfix calculator\n")
print("You should press space bar after each operator/operand.")

while True:
    str_in = input()
    tokens = str_in.split(" ")
    stack = []

    if tokens[0] == "q":
        break

    else:
        while len(tokens) > 0:
            item = tokens.pop(0)

            if item.isdigit():
                stack.append(int(item))

            elif item == "+":
                if len(stack) > 1:
                    stack.append(stack.pop() + stack.pop())
                else:
                    print("Invalid expression.")
                    break

            elif item == "-":
                if len(stack) > 1:
                    tmp = stack.pop()
                    stack.append(stack.pop() - tmp)
                else:
                    print("Invalid expression.")
                    break

            elif item == "*":
                if len(stack) > 1:
                    stack.append(stack.pop() * stack.pop())
                else:
                    print("Invalid expression.")
                    break

            elif item == "/":
                if len(stack) > 1:
                    tmp = stack.pop()
                    stack.append(stack.pop() / tmp)
                else:
                    print("Invalid expression.")
                    break

            elif item == "^":
                if len(stack) > 1:
                    tmp = stack.pop()
                    stack.append(pow(stack.pop(), tmp))
                else:
                    print("Invalid expression.")
                    break

            else:
                break

        print(stack.pop())
