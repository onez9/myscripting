def get_alph():
    rus_alph = 'абвгдеёжзийклмнопрстуфхцчшщъыьэюя'
    eng_alph = 'abcdefghijklmnopqrstuvwxyz'
    symb = ' :;!?&-+=()*/.,1234567890'
    alph = rus_alph + rus_alph.upper() + eng_alph + eng_alph.upper() + symb
    return alph


def get_bit(pos, shift):
    mask = 1 << shift
    sign = (pos & mask) >> shift
    return sign


def get_text(file_name):
    with open(file_name, mode='r', encoding='utf-8') as f:
        text = f.read().split('\n')
    return text

