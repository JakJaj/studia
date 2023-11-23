def evalRPN(tokens):
    stack = []
    if len(tokens) == 1:
        return tokens[0]
    for i in tokens:
        
        if i not in ['+','-','/','*']:
            stack.append(i)
        else:
            a = int(stack.pop())
            b = int(stack.pop())
            if i == '+':
                result = b + a
            elif i == '-':
                result = b - a
            elif i == '/':
                result = b / a
            else:
                result = b * a
                
            stack.append(result)
        
    return result
tokens1 = ["2","1","+","3","*"] #9

tokens2 = ["4","13","5","/","+"] #6

tokens3 = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"] #22

print(evalRPN(tokens1))
print(evalRPN(tokens2))
print(evalRPN(tokens3))