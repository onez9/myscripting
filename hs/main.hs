addstring :: (String, String) -> (String, String)
addstring (a,b) = (x1, x2) 
    where
        x1 = a ++ "i am string one"
        x2 = b ++ "i am string two"



calculateTime :: Int -> Int
calculateTime timeInS =
    let threshold  = 40
        correction = 120
        delta      = 8
    in
    if| timeInS <  threshold -> timeInS + correction
      | timeInS >= threshold -> timeInS + delta + correction

main = do
    putStrLn "Demo to show wherefunction in Haskell !!!"
    putStrLn "Calling function to calculate the values using where function !!!"


    print(addstring "hello " "bye")
    -- let result1 = addstring "hello " "bye "
    -- let result2 = addstring("world ", "happy ")
    -- let result3 = addstring("shopping ", "everyday ")
    -- let result4 = addstring("enjoy ", "moment ")
    -- let result5 = addstring("good day ", "always ")
    -- let result6 = addstring("great ", "things ")



    -- print("result one is ")
    -- print (result1)
    -- print("result two is ")
    -- print (result2)
    -- print("result three is ")
    -- print (result3)
    -- print("result four is ")
    -- print (result4)
    -- print("result five is ")
    -- print (result5)
    -- print("result six is ")
    -- print (result6)