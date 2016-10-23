word, key = input("enter the word: "), int(input("enter the key: "))
for c in word:
    offset = ord('A') if c.isupper() else ord('a')
    print(chr((((ord(c) + key) - offset) % 26) + offset), end="")
print()
