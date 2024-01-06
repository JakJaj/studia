import random

random = random.randrange(49 + 1)
guess = 0
tries = 0

while random != guess:

    tries += 1
    guess = int(input("Guess the number between 1 and 50 "))

    if guess < random:
     print("Number is bigger")
    elif guess > random:
     print("Number is smaller")

print(f"""
Congratulation you manage to guess the right number
The number that you guessed was {random}
You guessed it in {tries} tryies.""")