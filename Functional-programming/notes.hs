{-
    operacje na listach:

take 3 [2,3,4,5]   => [2,3,4]
drop 3 [2,3,4,5]   => [5]

init [2,3,4,5]     => [2,3,4]
tail [2,3,4,5]     => [3,4,5]
head [2,3,4,5]     => 2
last [2,3,4,5]     => 5

length [2,3,4,5]   => 4
reverse [1,2,3,4]  => [4,3,2,1]

[1,2] ++ [3,4]     => [1,2,3,4]
2 : [1,2,3]        => [2,1,2,3]

[2,3,4,5] !! 1     => 3
[2,3,4,5] !! 4     => *** Exception: Prelude.!!: index too large

[0..10]            => [0,1,2,3,4,5,6,7,8,9,10]
[0,2..]            => [0,2,4,6,8,10...]
['A'..'Z']         => "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

repeat 4           => [4,4,4,4...]
cycle [1,2,3]      => [1,2,3,1,2,3,1,2,3,1...]
elem 4 [3,2,4]     => True
splitAt 2 [2,1,3,4]=> ([2,1],[3,4])
maximum [2,1,4,3]  => 4
minimum [2,1,4,3]  => 1

sum [2,3,4]     => 9
product [2,3,4] => 24

all (<10) [1,3,5,7,9]    => True
any (1==) [0,1,2,3,4,5]  => True

and [True,True,False,True] => False
or  [True,True,False,True] => True

map (\x -> x - 10) [1..10] => [-9,-8,-7,-6,-5,-4,-3,-2,-1,0]
map (/ 10) [1..10]         => [0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0]
map (10 /) [1..10]         => [10.0,5.0,3.3333333333333335,2.5,2.0,1.6666666666666667,1.4285714285714286,1.25,1.1111111111111112,1.0]

filter (\x -> 2 * x == 4) [1..10] => [2]
filter (== 10) [1..10]            => [10]
filter (even)  [1..10]            => [2,4,6,8,10]
filter (odd)   [1..]              => [1,3,5,7,9,11,13,15,17,19,21,23,25,27,29...]

takeWhile (<10)  [2,4..]    => [2,4,6,8]
takeWhile (==10) [2,4..]    => [ ]
takeWhile (==2)  [2,4..]    => [2]

dropWhile (==2)  [2..10]         => [3,4,5,6,7,8,9,10]
dropWhile (\x -> x <= 5) [2..10] => [6,7,8,9,10]

concatMap (reverse) ["Ala","ma","kota"]           => "alAamatok"
concatMap (filter (>3)) [[1,2,3],[3,4,5],[5,6,7]] => [4,5,5,6,7]

take 10 $ iterate (* 2) 1 => [1,2,4,8,16,32,64,128,256,512]

zip [1,2,3] "abc" => [(1,'a'),(2,'b'),(3,'c')]

zipWith (+)  [1,2,3]   [4,5,6]     => [5,7,9]
zipWith (++) ["a","a"] ["b","c"]   => ["ab","ac"]
zipWith (++) ["a"]     ["b","c"]   => ["ab"]

unzip [(1,2),(2,3),(3,4)] => ([1,2,3],[2,3,4])

replicate 10 1    => [1,1,1,1,1,1,1,1,1,1]
replicate 5 "abc" => ["abc","abc","abc","abc","abc"]

foldr (++) "" ["abc","abc","ccc"] => "abcabcccc"
foldl (-) 0 [1,2,3,4] => ((((0-1)-2)-3)-4) = -10
foldr (-) 0 [1,2,3,4] => (1-(2-(3-(4-0)))) = -2
foldl (\acc y -> acc + y) 10 [1,1,1,1]     => 14
foldl (\acc y -> (fst acc + y, 0)) (0,0) [1,1,1,1] => (4,0)
-}

lista :: [Int] -> String
lista [ ]           = "Lista jest pusta"
lista (x : [ ])     = "Lista zawiera tylko " ++ show x
lista (x : y : [ ]) = "Lista zawiera tylko " ++ show x ++ " oraz " ++ show y
lista (x : xs)      = "Lista zaczyna sie od " ++ show x ++ ", reszta to " ++ show xs

{-
    operatory: 

Matematyczne: +, -, /, *
Porównań: >, >=, <, <=, ==, /=
Logiczne: &&, ||, notn
mod - reszta modulo
div - dzielenie całkowite
abs - wartosc bezwzgledna
even - czy liczba jest parzysta
odd  - czy liczba jest nieparzysta

round 3.4   => 3
floor 3.4   => 3
ceiling 3.4 => 4

gcd 22 4    => 2

2 == 2         => True
(/=) 3 2       => True
False || False => False
not True       => False
(+) 3 2        => 5
3 + 2          => 5
3 / 2          => 1.5
3 `div` 2      => 1
div 3 2        => 1
abs (-2)       => 2
even (-2)      => True
odd (69 + 2137)=> False

-}

f :: Fractional a => a -> a -> a
-- f x y = 3 * y / x
-- f x y = (/) (3*y) x
-- f x y = flip (/) x (3*y)
-- f x y = flip (/) x ((*) 3 y)
-- f x y = (flip (/) x . (*) 3) y
-- f x = (flip (/) x).(*)3
-- f x = (.) (flip (/) x ) (*3)
-- f x = flip (.) (*3) (flip (/) x )
-- f x = (flip (.) (*3) . (flip (/))) x 
f = (flip (.) (*3) . (flip (/)))
 
divider :: Float -> Float -> Float
-- divider a b = (2) * (b / a)
-- divider a b = (*) (2) (b / a)
-- divider a b = (*) (2) ((/) b a)
-- divider a b = (*) (2) (flip (/) a b)
-- divider a b = ((*) (2) . (flip (/) a)) b
-- divider a = ((*) (2) . (flip (/) a))
-- divider a = (.) ((*) (2)) (flip (/) a)
-- divider a = ((.) ((*) (2)) . (flip (/))) a
-- divider = ((.) ((*) (2)) . (flip (/))) 
divider = ((.) (*2) . (flip (/)))
 
zad1 :: [Int] -> [Int]
zad1 = filter (>5)
 
zad2 :: [Int] -> Int
-- zad2 list = (length (filter (\x -> x /= 0)) list)
-- zad2 list = (length . (filter (\x -> x /= 0))) list
-- zad2 = (length . (filter (\x -> x /= 0)))
-- zad2 = (length . (filter ((/=) 0)))
zad2 = length . (filter ((/=) 0))
 
zad3 :: Int -> [Int] -> [Int]
-- zad3 x list = map (\y -> y * x) list
-- zad3 x = map (\y -> y * x)  
-- zad3 x = map (\y -> (*) y x)  
-- zad3 x = (map . (\y -> (*) y)) x
-- zad3 = (map . (\y -> (*) y))
zad3 = (map . (*))
 
zad4 :: [Double] -> Double -> [Double]
-- zad4 list x = map (\y -> y / x) list 
-- zad4 list x = flip map list (/x)
-- zad4 list x = flip map list (flip (/)x)
-- zad4 list x = (flip map list . (flip (/))) x
-- zad4 list = (flip map list . (flip (/)))
-- zad4 list = (.) (flip map list) (flip (/))
-- zad4 list = flip (.) (flip (/)) (flip map list) 
-- zad4 list = (flip (.) (flip (/)) . (flip map)) list 
zad4 = (flip (.) (flip (/)) . (flip map))
 
zad5 :: Ord a => [a] -> a -> [a]
-- zad5 l a = [x | x <- l, x > a]
-- zad5 l a = filter (>a) l
-- zad5 l a = flip filter l (>a)
-- zad5 l a = flip filter l (flip (>) a)
-- zad5 l a = (flip filter l . (flip (>))) a
-- zad5 l = (flip filter l . (flip (>)))
-- zad5 l = (.) (flip filter l) (flip (>))
-- zad5 l = flip (.) (flip (>)) (flip filter l)
-- zad5 l = (flip (.) (flip (>)) . (flip filter)) l
zad5 = (flip (.) (flip (>)) . (flip filter))
 
-- zad2017 [1,2,3,4] = [[], [1], [1,2], [1,2,3], [1,2,3,4]]
-- zad2017 "tekst" = ["", "t", "te", "tek", "teks", "tekst"]
zad2017 :: [a] -> [[a]]
zad2017 list = foldr (\acc x -> [] : map (\y -> acc : y) x) [[]] list
 
 
-- zad2020 list = map (\(a,b) -> 3 * (a+b)) (zip list [1..10])
zad2020 :: [Int] -> [Int]
-- zad2020 list = map (\(a,b) -> 3 * (a+b)) (zip list [1..10])
-- zad2020 list = map (\(a,b) -> 3 * (a+b)) (flip zip [1..10] list)
-- zad2020 list = (map (\(a,b) -> 3 * (a+b)) . (flip zip [1..10])) list
-- zad2020 = (map (\(a,b) -> 3 * (a+b)) . (flip zip [1..10])
-- zad2020 = (map (\(a,b) -> (*) (3) (a + b)) . (flip zip [1..10]))
-- zad2020 = (map (\number  -> (*) (3) (uncurry (+) number)) . (flip zip [1..10]))
-- zad2020 = (map ((*) (3). (uncurry (+))) . (flip zip [1..10]))
zad2020 = (map ((*3). (uncurry (+))) . (flip zip [1..10]))
 
zad2021 :: [(Int, Int)] -> Int -> Int
-- zad2021 list u = foldr(\(a, b) acc -> (a - b) * acc) u list
-- zad2021 list u = foldr (\(a, b) acc -> (*) (a - b) (acc)) u list
-- zad2021 list u = foldr (\number acc -> (*) (uncurry (-) number) (acc)) u list
-- zad2021 list u = foldr (\number -> (*) (uncurry (-) number)) u list
-- zad2021 list u = foldr ((*) . (uncurry (-))) u list
-- zad2021 list u = flip (foldr ((*) . (uncurry (-)))) list u
-- zad2021 list = flip (foldr ((*) . (uncurry (-)))) list
zad2021 = flip (foldr ((*) . (uncurry (-))))
 
zad2019 :: [[Int]] -> [Int]
-- zad2019 list = concat (filter (\x -> even (sum x)) list)
-- zad2019 list = (concat . (filter (\x -> even (sum x)))) list
-- zad2019 = (concat . (filter (\x -> even (sum x))))
zad2019 = (concat . (filter ((even . (sum)))))