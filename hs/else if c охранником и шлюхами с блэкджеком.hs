



{-# LANGUAGE MultiWayIf #-}

func::Int->String
func def = 
    if | def==1 -> "Привет юный пидр!"
       | def==2 -> "я хочу чтобы ты сдох"
       | def==3 -> "Почему бы тебе не умереть?"
       | otherwise -> "Найдеюсь ты скоро умрешь)"


main=putStrLn func 2