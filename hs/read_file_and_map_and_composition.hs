import System.IO  
import Control.Monad
import Data.Char
-- main = do  
--     let list = []
--     handle <- openFile "test.txt" ReadMode
--     contents <- hGetContents handle
--     let singlewords = words contents
--         list = f singlewords
--     print list
--     hClose handle   

f::String->String
f x = "____"++x++"____"

-- Наш собственный оператор композиции.
(<+>) f g = \x -> f (g x)
-- (<lolol1>) f g = \x -> f (g x)

toUpperCase::String->String
toUpperCase str=map toUpper str



main = do  
    putStrLn(f "math") -- #1
    putStrLn . f $ "math" -- #2
    -- putStrLn <lolol1> f $ "math"

    putStrLn . toUpperCase $ "haskell.org"
    
    print . map(toUpper) $ "sfoddsfoower" --partical apply -- частичное приеменение -- функции map передали один аргумент вместо 2
    -- write File
    -- let sometxt="aaa"++"bbb"
    -- writeFile "test.txt" sometxt




    
    -- let sometxt="hello"++" world"
    -- appendFile "test.txt" sometxt

    -- -- read File
    -- contents <- readFile "test.txt"
    -- putStrLn(contents)




    -- print . map readInt . words $ contents
    -- alternately, main = print . map readInt . words =<< readFile "test.txt"

    -- readInt :: String -> Int
    -- readInt = read

-- f :: [String] -> [Int]
-- f = map read