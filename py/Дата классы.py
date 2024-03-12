from dataclasses import dataclass, asdict
from typing import Any


@dataclass
class User:
    name: str
    age: int

class UserHandle:
    def __init__(self, name, age) -> None:
        # что это такое? почему а почему так?
        self.user: User = User(name, age)


    def get_dataclass(self):
        return asdict(self.user)


    def edit(self, key, value):
        self.user.__dict__[key] = value


if __name__ == '__main__':
    # конвертирует класс в словарь или обратно, как я понял
    a = UserHandle('Игорь', 21)
    print(a)
    print(a.__dict__)
    print(a.get_dataclass())
























