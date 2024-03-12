

class Someclass
  attr_accessor :x, :y, :z
  def initialize x, y, z
    @x = x
    @y = y
    @z = z
  end

  def +(other)
    Someclass.new @x * other.x, @y * other.y, @z * other.z
  end

  def -(other)
    Someclass.new @x - other.x, @y - other.y, @z - other.z
  end

  def *(other)
    Someclass.new @x * other.x, @y * other.y, @z * other.z
  end

  def /(other)
    Someclass.new @x / other.x, @y / other.y, @z / other.z
  end

  def showXYZ
    puts "x = #{@x}, Y = #{@y}, Z = #{@z}"
  end
end


a = Someclass.new 2, 2, 2

b = Someclass.new 5, 5, 5

c1 = a + b
p c1
c1.showXYZ

c2 = a - b
p c2
c2.showXYZ

c3 = a * b
p c3
c3.showXYZ

c4 = a / b
p c4
c4.showXYZ