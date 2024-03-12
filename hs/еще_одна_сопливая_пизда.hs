calculateTime :: Int -> Int
calculateTime timeInS =
    let threshold = 40 in
    if | timeInS < threshold -> timeInS + correction
       | otherwise -> timeInS + delta + correction
       where
            correction = 120
            delta      = 8



main=do
    print(calculate 3)