contacts = []
def search_person(name):
    for contact in contacts:
        if contact["name"] == name:
            return contact
    return None
def delete_person(name):
    for contact in contacts:
        if contact['name'] == name:
            contacts.remove(contact)
def add_person():
    name = input("Enter name: ")
    age = input("Enter age: ")
    email = input("Enter email: ")
    person = {"name": name, "age": age, "email": email}
    contacts.append(person)
    return person
print("Hi, welcome to contact management system.")
print()
flag = True
while flag:
    command = input("You can either 'Add', 'Delete' or 'Search' and -1 for quit: ")
    if command == 'add':
        add_person()
    elif command == 'delete':
        name = input("Enter the name of person you want to delete: ")
        contact = delete_person(name)
    elif command == 'search':
        search = input("Enter search query:(name) ")
        contact = search_person(search)
        print()
        print()
        if contact == None:
            print('contact not found')
        else:
            print("Contact found: ")
            print(contact)
    elif command == "-1":
        flag = False
    else:
        print("Enter valid command")
    print(contacts)
    
    
# file handling
with open("contacts.json", "r") as f:
    people = json.load(f)["contacts"]
    # some more logic if needed
    
# to write (dump) into the file:
with open("contacts.json", "w") as f:
    json.dump(d, { "contacts": people })