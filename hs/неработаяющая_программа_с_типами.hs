-- f::Num a=>a->a->a
-- f x y=x*x + y*y

-- x::Float
-- x=3.6
-- y::Int
-- y=6

-- import Ix
-- import Array

-- a = array (1,100) ((1,1) : [(i, i * a!(i-1)) | i <- [2..100]])

-- module Main where 

-- import Data.List

arr=["TCP", "UDP", "DCCP", "SCTP"]

print()
main::IO();
main=do
    -- putStrLn(tail(arr)) - this a function get parametr string consequently return error
    print(head(arr)) -- first
    print(last(arr)) -- last
    print(tail(arr)) -- tail - хвост
    print(length(arr)) -- длина списка
    c<-getChar -- type Char
    putChar c
    s<-getLine -- type string
    putStrLn(s)
-- main=do
--     print(arr)
-- class  (Ord a) => Ix a  where
--     range       :: (a,a) -> [a]
--     index       :: (a,a) a -> Int
--     inRange     :: (a,a) -> a -> Bool

-- array :: (Ix a) => (a,a) -> [(a,b)] -> Array a b

-- squares=array(1,100)[(i, i*i) | i<-[1..100]]


-- main=print(f x y)
-- main=print(squares)
--main=print(f 3.3 6.3)

