



{-# LANGUAGE MultiWayIf #-}


calculateTime :: Int -> Int
calculateTime timeInS =
  let threshold = 40 in
  if | timeInS < threshold -> timeInS + correction
     | otherwise -> timeInS + delta + correction
  where
    -- Это промежуточное выражение зависит от аргумента...
    correction = timeInS * 2
    -- А это - от другого выражения...
    delta      = correction - 4

main=print(calculateTime 5)