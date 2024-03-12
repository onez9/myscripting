f::Num a=>a->a->a -- пусть - а это тип, принадлежащий к классу типов Num

f x y=x*x + y*y


main = print(f 3 3.5)
