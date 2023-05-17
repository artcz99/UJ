--zad 2.2
--multOrSum 2 4 => "Iloczyn x=2 i y=4 jest wiekszy"
multOrSum :: Int -> Int -> String
multOrSum x y = if x*y > x+y then "Iloczyn " ++ info
                else "Suma " ++ info
    where  
        info = "x=" ++ show x ++ " i y=" ++ show y ++ " jest wiekszy"

--zad 2.3
--kongruencja => [67,235,403,571,739,907,1075...]
kongruencja :: [Int]
kongruencja = [x | x <- [1..10000], x `mod` 6 == 1 && x `mod` 7 == 4 && x `mod` 8 == 3]

--zad 2.4
--dzielniki 9 => [1,3]
dzielniki :: Int -> [Int]
dzielniki n = [x | x <- [1..zakres], n `mod` x == 0]
    where
        zakres = n `div` 2

--zad 2.5
--ktoraCwiartka [(1,2),(5,4),(0,4),(0,0),(-4,-2),(-4,2),(4,1)] => 1
ktoraCwiartka :: [(Int,Int)] -> Int
ktoraCwiartka [ ] = 0
ktoraCwiartka [x] = cwiartka x
ktoraCwiartka (x : xs) = 



cwiartka :: (Int, Int) -> Int
cwiartka (0, 0) = 0
cwiartka (0, y) | y > 0     = 6
                | otherwise = 8
cwiartka (x, 0) | x > 0     = 5
                | otherwise = 7
cwiartka (x, y) | x > 0 && y > 0 = 1
                | x > 0 && y < 0 = 4
                | x < 0 && y > 0 = 2
                | otherwise      = 3