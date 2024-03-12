
main = do
    print "Как вас зовут?"
    putStrLn "Как вас зовут?"
    name <- getLine
    print ("Привет " ++ name ++ "!")
    putStrLn("Привет" ++ name++"!")
