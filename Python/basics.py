# this is a comment
print("Hello world")

a = 1 # int data type
b = 3.78 # float data type
c = True # boolean data type

# take input from user
name = input("Type your name: ")
print("Name of the user is", name)
verdict = input("Do you want to play a game: ")
play = verdict == "yes"
if play:
    print("We are going to play the game")
else:
    print("We are not playing the game")

# building a basic calculator
operand1 = input("Enter 1st number ")
operand2 = input("Enter 2nd number ")
sign = input("Enter the operation ")
result = 0
ans = True
try:
    operand1 = float(operand1)
    operand2 = float(operand2)
    if sign == "+":
        result = operand1 + operand2
    elif sign == "-":
        result = operand1 - operand2
    elif sign == '*':
        result = operand1 * operand2
    elif sign == '/':
        result = operand1 / operand2
    else:
        ans = False
        print("Enter valid sign or operands")
    if ans:
        print(result)
except:
    print("please enter valid operands")

# loops
while True:
    operand1 = input("Enter operand1 ")
    operand2 = input("Enter operand2 ")
    try:
        operand1 = float(operand1)
        operand2 = float(operand2)
        break
    except:
        print("Invalid numbers, try again")
sign = input("Enter operation: ")
ans = True
if sign == "+":
        result = operand1 + operand2
elif sign == "-":
    result = operand1 - operand2
elif sign == '*':
    result = operand1 * operand2
elif sign == '/':
    result = operand1 / operand2
else:
    ans = False
    print("Enter valid sign or operands")
print(result)

# functions
def getNumber():
    while True:
        operand = input("Enter a number: ")
        try:
            operand = float(operand)
            break
        except Exception as e:
            print("Enter correct number")
    return operand
operand1 = getNumber()
operand2 = getNumber()
print(operand1, operand2)

# for loops
for i in range(10):
    print(i)

# lists
numbers = [1, 2, 3, 4, 5]
print(numbers[0])
print(numbers[-1]) # used to print last element of a list

# iterating through the list
for num in numbers:
    print(num)

# or
for i in range(len(numbers)):
    num = numbers[i]
    print(num)

names = []
ages = []
emails = []

print("Before operations:", names, ages, emails)

n = int(input("Enter the number of people: "))
for i in range(n):
    name = input("Enter name: ")
    names.append(name)
    age = input("Enter age: ")
    ages.append(age)
    email = input("Enter email: ")
    emails.append(email)    

print("After operations: ")
print(names, ages, emails)

# use of dictionary
persons = []
for i in range(n):
    name = input("Enter name: ")
    age = input("Enter age: ")
    email = input("Enter email: ")
    person = {
        'name': name,
        'age': age,
        'email': email,
    }
    persons.append(person)
print(persons['name'])