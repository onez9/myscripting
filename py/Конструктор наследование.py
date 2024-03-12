class Person:
  def __init__(self, firstname, middlename, lastname, age, sex):
    self.firstname = firstname
    self.middlename = middlename
    self.lastname = lastname
    self.age = age
    self.sex = sex


  def display(self):
    print(f"firstname: #{self.firstname}")
    print(f"middlename: #{self.middlename}")
    print(f"lastname: #{self.lastname}")
    print(f"age: #{self.age}")
    print(f"sex: #{self.sex}")


class Employee(Person):
  def __init__(self, firstname, middlename, lastname, age, sex, company):
    super().__init__(firstname, middlename, lastname, age, sex)
    self.company = company


  def display(self):
    super().display()
    print(f"namecompany: {self.company}")


p1 = Employee('Захар', 'Владимирович', 'Арамилев', 21, 1, "Tesla")

p1.display()

arr = [1, 2, 3, 4]
arr2 = arr
print(f"arr: #{arr}")
print(f"arr2: #{arr2}")
arr += [1, 3, 3]
print(f"arr: #{arr}")
print(f"arr2: #{arr2}")
