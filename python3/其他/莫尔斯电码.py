"""只支持英文, 逗号, 点号"""

MORSE_CODES = {
    "A": "01", "B": "1000", "C": "1010", "D": "100", "E": "0", "F": "0010", "G": "110", "H": "0000", "I": "00", "J": "0111", "K": "101", "L": "0100", "M": "11", 
    "N": "10", "O": "111", "P": "0110", "Q": "1101", "R": "0101", "S": "000", "T": "1", "U": "001", "V": "0001", "W": "011", "X": "1001", "Y": "1011", "Z": "1100", 
    "1": "01111", "2": "00111", "3": "00011", "4": "00001", "5": "00000", "6": "10000", "7": "11000", "8": "11100", "9": "11110", "0": "11111",
    ",": "110011", ".": "010101", " ": " ","none": "*"
}

def get_key (dict_obj, value):
    for v in dict_obj.items():
        if v[1] == value:
            return v[0]
    # return (k for k, v in dict_obj.items() if v == value)


def trans_to_morse(sourse_code):
    morse_code = str()
    for word in sourse_code:
        for code in MORSE_CODES:
            if word.upper() == code:
                morse_code += MORSE_CODES[word.upper()]
        else:
            morse_code += MORSE_CODES["none"]
    return morse_code


def trans_to_word(morse_code):
    sourse_code = str()
    for code in morse_code.split("*"):
        word = get_key(MORSE_CODES, code)
        if word == None:
            word = " "
        sourse_code += word
    return sourse_code


h = "hello world."
c = "0000*0*0100*0100*111* *011*111*0101*0100*100*010101*"
print(trans_to_morse(h))
print(trans_to_word(c))
