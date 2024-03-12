def get_text(file_name):
    with open(file_name, mode='r', encoding='utf-8') as f:
        text = f.read().split('\n')
    return text


def get_alph():
    rus_alph = 'абвгдеёжзийклмнопрстуфхцчшщъыьэюя'
    eng_alph = 'abcdefghijklmnopqrstuvwxyz'
    symb = ' :;!?&—-+=()*/.,1234567890'
    alph = rus_alph + rus_alph.upper() + eng_alph + eng_alph.upper() + symb
    return alph


def code(alph, key):
    tabs = text
    with open(f'output.txt', mode='w', encoding='utf8') as w:
        for i in range(len(tabs)):
            line = ''
            for j in range(len(tabs[i])):
                line += alph[(alph.index(tabs[i][j]) + key) % len(alph)]
            if i == len(tabs) - 1:
                line = line + '^'
            else:
                line = line + '~'
            w.write(line + '\n')


alph = get_alph()
text = get_text('input.txt')
key = 11342314
code(alph, key)
