
import Data.Char -- toUpper, toLower
import Data.List.Utils -- replace
-- replace :: String -> String -> String -> String

main::IO()
main=putStrLn result where
    first  = replace $ "http"
    second = first    "https"
    result = second   "http://google.com"


    