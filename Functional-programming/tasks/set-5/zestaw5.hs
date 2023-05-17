--zad 5.1
--wielkieLitery ["TeSt","test",""] => ["TS","",""]
wielkieLitery :: [String] -> [String]
wielkieLitery list = map (\x -> filter (\y -> elem y ['A'..'Z']) x) list

--zad 5.2
--dlugoscPalindromow ["kajak", "ananas", "owocowo", "anna", "artur"]
dlugoscPalindromow :: [String] -> Int
dlugoscPalindromow str_list = sum (map (\x -> calculate x) str_list)
    where
        calculate str | czyPalindrom str == True = length str
                      | otherwise                = 0
        czyPalindrom str = str == reverse str 

--zad 5.3

fib :: (Integer,Integer) -> [(Integer,Integer)]
fib point = [pointy] ++ fib pointy
    where
        pointy = (snd $ point, (snd $ point) + (fst $ point))

--zad 5.4
--dlugosc "abc" => 3
dlugosc :: [a] -> Int
dlugosc list = sum (map (\x -> 1) list)

--zad 5.5
-- slowaDlugosci :: Char -> Char -> Integer -> [String]
-- slowaDlugosci c1 c2 n = 

--zad 5.6
quickSort :: [Int] -> [Int]
quickSort [ ]      = [ ]
quickSort (x : xs) = lower ++ [x] ++ bigger
    where 
        lower  = quickSort [low | low <- xs, low <= x]
        bigger = quickSort [big | big <- xs, big >  x]