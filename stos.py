stos = []

s = "[]()"


for i in s:

    if i in "[{(":
        stos.append(i)
        
    else:
        pop = stos.pop()
        if i == "]" and pop != "[":
            return False
        if i == "}" and pop != "{":
            return False
        if i == ")" and pop != "(":
            return False
        
        
print(f"Stos wyglada nastepujaco: {stos}")