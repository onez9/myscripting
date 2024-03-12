class Person
  def initialize(firstname, middlename, lastname, age, sex)
    @firstname = firstname
    @middlename = middlename
    @lastname = lastname
    @age = age
    @sex = sex
  end

  def display
    p "firstname: #{@firstname}"
    p "middlename: #{@middlename}"
    p "lastname: #{@lastname}"
    p "age: #{@age}"
    p "sex: #{@sex}"
  end
end


class Employee < Person
  def initialize(firstname, middlename, lastname, age, sex, company)
    @company = company
    super(firstname, middlename, lastname, age, sex)

  end

  def display
    super
    p "company: #{@company}"
  end


end

p1 = Employee.new 'Захар','Владимирович', 'Арамилев', 21, 1, "Квантовый киберотдел Несуществующей организации"

p1.display

arr = [1, 2, 3, 4]
arr2 = arr
p "arr: #{arr}"
p "arr2: #{arr2}"
arr += [1, 3, 3]
p "arr: #{arr}"
p "arr2: #{arr2}"
