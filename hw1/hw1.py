from typing import List

def main()  ->  None:
    encryptedMessage: List[str] = []

    shift: int = int(input("What is your shift (ints only)? "))
    message: str = input("What is your message? ")

    char: str
    for char in message:
        if char == " ":
            encryptedMessage.append(char)
            continue
        unicodeValue: int = ord(char)
        unicodeValue += shift
        encryptedMessage.append(chr(unicodeValue))

    print(f"""Encrypted Message:
    {"".join(encryptedMessage)}""")




if __name__ == "__main__":
    main()
