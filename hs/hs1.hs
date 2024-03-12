add::Integer->Integer->Integer --function declaration
add x y = x + y

fact::Integer->Integer
fact 0 = 1
fact x = x * fact(x - 1)

-- через охранников [Guard]
fact1::Integer->Integer
fact1 x|x == 0 = 1
       |x /= 0 = x * fact(x - 1)


-- key
roots2::(Double, Double, Double)->(Double, Double)
roots2 (a, b, c) = (x1, x2) where
   x1 = (-b + d**0.5) / (2*a)
   x2 = (-b - d**0.5) / (2*a)
   d = b**2 - 4*a*c


roots1 :: (Float, Float, Float) -> (Float, Float)
roots1 (a,b,c) = (x1, x2) where
   x1 = e + sqrt d / (2 * a)
   x2 = e - sqrt d / (2 * a)
   d = b * b - 4 * a * c
   e = - b / (2 * a)


main = do
   putStrLn "roots1: "
   print (roots1(1,-8,6))
   putStrLn "roots2: "
   print (roots2(1,-8,6))


-- main::IO()
-- main=print $ roots 1 2 3
-- main = do
--    putStrLn "The roots of our Polynomial equation are:"
--    print (roots(1,-8,6))
