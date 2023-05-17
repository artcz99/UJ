--zad 1.1
--funkcja 3 4 => 1.0416666666666667
funkcja :: Double -> Double -> Double
funkcja 0 _ = 0
funkcja _ 0 = 0
funkcja x y = ((x * x) + (y * y)) / (2 * x * y)

--zad 1.2
--sumaWartosci f g 1000 100 => 2300
sumaWartosci :: (Int -> Int) -> (Int -> Int) -> Int -> Int -> Int
sumaWartosci f g x y = (f x) + (g y)

f :: Int -> Int
f x = 2 * x

g :: Int -> Int
g y = 3 * y

--zad 1.3
--ocena' 5.0 => "brawo!"
ocena :: Double -> String
ocena 2.0 = "niezaliczone"
ocena 5.0 = "brawo!"
ocena x   = "wpisane masz " ++ show x

ocena' :: Double -> String
ocena' x | x == 2.0  = "niezaliczone"
         | x == 5.0  = "brawo!"
         | otherwise = "wpisane masz " ++ show x

ocena'' :: Double -> String
ocena'' x = if x == 2.0 then 
                "niezaliczone" 
            else if x == 5.0 then 
                "brawo!" 
            else 
                "wpisane masz " ++ show x

--zad 1.4a
--stirling 5 4 => 10
stirling :: Int -> Int -> Int
stirling 0 0 = 1
stirling n 0 = 0
stirling n k | n == k = 1
             | otherwise = (n - 1) * (stirling (n - 1) k) + (stirling (n - 1) (k - 1))
            
--zad 1.4b
--iloczynListy [1,2,3,4] => 24
--iloczynListy [1..1000] => 40238726007709377354370243392300...
iloczynListy :: [Integer] -> Integer
iloczynListy (x : [ ]) = x
iloczynListy (x : xs)  = x * iloczynListy xs

--zad 1.5
--merge [1,4,6] [0,2,10,12] => [0,1,2,4,6,10,12]
--mergeSort [6,2,1,50,0,-1,2] => [-1,0,1,2,2,6,50]
merge :: [Int] -> [Int] -> [Int]
merge [ ] [ ] = [ ]
merge xs [ ]  = xs
merge [ ] ys  = ys
merge (x : xs) (y : ys) | x <= y    = x : merge xs (y : ys)
                        | otherwise = y : merge (x : xs) ys

mergeSort :: [Int] -> [Int]
mergeSort [ ] = [ ]
mergeSort [x] = [x]
mergeSort xs = merge (mergeSort firstHalf) (mergeSort secondHalf)
    where 
        firstHalf = take (length xs `div` 2) xs
        secondHalf = drop (length xs `div` 2) xs

--zad 1.6a
--czyDoskonala 6 => True
czyDoskonala :: Int -> Bool
czyDoskonala x = if (sumList (dzielniki (x, [1])) == x) then True else False

sumList :: [Int] -> Int
sumList [ ] = 0
sumList (x : [ ]) = x
sumList (x : xs)  = x + sumList xs

dzielniki :: (Int, [Int]) -> [Int]
dzielniki (_, [ ]) = [ ]
dzielniki (n, xs) | n <= 0 = [ ]
                  | ((n > 0) && (n `div` 2 > (head xs)) && (mod n (head xs) == 0)) = dzielniki(n, [(head xs) + 1, (head xs)] ++ tail xs)
                  | ((n > 0) && (n `div` 2 > (head xs)) && (mod n (head xs) /= 0)) = dzielniki(n, [(head xs) + 1] ++ tail xs)
                  | otherwise = if (mod n (head xs) == 0) then xs else tail xs

--zad 1.6b
--maksimum [2,4,100,0,-4,10] => 100
maksimum :: [Int] -> Int
maksimum [ ]       = -1
maksimum (x : [ ]) = x
maksimum (x : xs)  = if (x > maksimum xs) then x else maksimum xs 

--zad 1.7
--sumPosNeg [1,-4,2,1,1,4,-3] => (9, -7)
sumPosNeg :: [Int] -> (Int, Int)
sumPosNeg [ ] = (-1, -1)
sumPosNeg x = (sumList(filter (>0) x), sumList(filter (<0) x))

--zad 1.8
--commonPrefix "slonko" "slimak" => "sl"
commonPrefix :: String -> String -> String
commonPrefix [ ] [ ] = ""
commonPrefix _   [ ] = ""
commonPrefix [ ] _   = ""
commonPrefix (x : xs) (y : ys) = if x == y then [x] ++ (commonPrefix xs ys) else ""

--zad 1.9
--int2Bin 10 => [1,0,1,0]
--bin2Int [1,0,1,0] => 10
int2Bin :: Int -> [Int]
int2Bin 1 = [1]
int2Bin x | x `mod` 2 == 0 = int2Bin (x `div` 2) ++ [0]
          | otherwise      = int2Bin (x `div` 2) ++ [1]

bin2Int :: [Int] -> Int
bin2Int [0] = 0
bin2Int [1] = 1
bin2Int (x : xs) | x == 0 = bin2Int xs
                 | x == 1 = (pow 2 (length xs)) + bin2Int xs

pow :: Int -> Int -> Int
pow x 0 = 1
pow x 1 = x
pow x y = x * pow x (y - 1)

