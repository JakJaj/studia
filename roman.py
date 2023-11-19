string = 'MCMXCIV'

values = {
            'I' : 1,
            'V' : 5,
            'X' : 10,
            'L' : 50,
            'C' : 100,
            'D' : 500,
            'M' : 1000
        }

number = 0

for i in range(len(string)):
    

    if i < len(string) - 1 and values[string[i]] < values[string[i+1]]:
        number -= values[string[i]]
    else:
        number += values[string[i]]

print(number)

        