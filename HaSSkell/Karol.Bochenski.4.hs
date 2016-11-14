import Data.List
import Data.Maybe
import Data.Char
import Puzzle
import Checker

-----------------------------------------------------
--                                                 --
--     Karol Bocheński, nr.indeksu 271484          --
--        Zad. nr 4, "Stawy i Grobla"              --
--                                                 --
-----------------------------------------------------

-- Cały program operuje na listach list par int'ów reprezentujązych stawy, grobla to zwyczajnie wszystkie pola nie zajęte przez stawy
-- później używam funkcji zamieniającą taką listę na listę list elementów typu field.

-- 4 funckcje osobno sprawdzające 4 możliwych sąsiadów danego pola i składające wynik do jednej listy,
-- mozna bylo to zalatwic uzywajac list comprehension jednak dla wiekszych testow to rozwiazanie okazalo sie troche szybsze

neighbour1:: (Int,Int) -> [(Int,Int)] -> Int -> Int -> [(Int,Int)]
neighbour1 (y,x) path limY limX
    | y > 1 && notElem (y-1,x) path = (y-1,x):neighbour2 (y,x) path limY limX
    | otherwise = neighbour2 (y,x) path limY limX
neighbour2 (y,x) path limY limX
    | y < limY && notElem (y+1,x) path = (y+1,x):neighbour3 (y,x) path limX
    | otherwise = neighbour3 (y,x) path limX
neighbour3 (y,x) path limX
    | x > 1 && notElem (y,x-1) path = (y,x-1):neighbour4 (y,x) path limX
    | otherwise = neighbour4 (y,x) path limX
neighbour4 (y,x) path limX
    | x < limX && notElem (y,x+1) path = [(y,x+1)]
    | otherwise = []

-- 3 Funkcje pomocnicze uzywane do skladania listy sasiadow z listą pól danego stawu

add_n::[a] -> [a] -> [[a]]
add_n [] ys = []
add_n xs ys = [x:ys| x <- xs]

add_m::[[a]] -> [a] -> [[a]]
add_m [] ys = []
add_m xs ys = [x ++ ys | x <- xs]

con_u [] ys = ys
con_u (x:xs) ys
    | notElem x ys = x: con_u xs ys 
    | otherwise  = con_u xs ys
   
-- prawdopodobnie najważniejsza funkcja programu uzywana do wyszukiwania stawów jak i sprawdzenia spójności grobli
-- dla podanej listy pól generuje jej "otoczkę" czyli wszystkich sąsiadów, bez powtórzeń
    
outline::[(Int,Int)] -> [(Int,Int)]-> Int -> Int -> [(Int,Int)]
outline [] _ _ _ = []
outline xs@(x:xs') path limY limX = sort(con_u (neighbour1 x p limY limX) (outline xs' p limY limX)) 
    where p = xs ++ path

-- funkcja expand bierze staw oraz wynik funkcji outline dla tego stawu  i tworzy nowe listy, każda z dodanym jednym z elementów outline dodanym do stawu
-- w efekcie każdy kolejny expand dla stawu o długości n generuje wszystkie stawy bez powtórzeń o długości n+1
    
expand::[[(Int,Int)]] -> [(Int,Int)]-> Int -> Int -> [[(Int,Int)]]
expand [] _ _ _ = []
expand (x:xs) path limY limX = con_u (map sort (add_n (outline x path limY limX) x)) (expand xs path limY limX)

-- funkcja gen pond, dla danej pary współrzędnych tworzy liste wszystkich stawów danej długości

gen_pond:: (Int,Int) -> [(Int,Int)]-> Int -> Int -> Int -> [[(Int,Int)]]
gen_pond (y,x) path 1 _ _ 
    | notElem (y,x) path  = [[(y,x)]]
    | otherwise           = []
gen_pond (y,x) path n limY limX = expand (gen_pond (y,x) path (n-1) limY limX) path limY limX

-- funkcja gen_ponds po kolei tworzy stawy dla podanej listy współrzędnych i długości

gen_ponds [] fieldsTaken _ _ = [fieldsTaken]
gen_ponds ((y,x,size):xs) path limY limX = [solution |
    let out = (outline path [] limY limX) ++ path,
    ponds <- gen_pond (y,x) out size limY limX,
    let path2 = ponds ++ path,
    solution <- gen_ponds xs path2 limY limX]

 
-- funkcja znajdujaca pierwsze pole nie zajęte przez stawy

first_dike::[(Int,Int)] -> Int -> Int -> (Int,Int)
first_dike xs limY limX = [(a,b)| a <- [1..limY], b <-[1..limX],notElem (a,b) xs] !! 0

-- predykat sprawjący czy grobla nie jest szeroka w żadnym punkcie na planszy

wide_dike::Int -> Int -> [(Int,Int)] -> Bool
wide_dike limY limX xs = aux xs limY limX 1 1 where
    aux xs limY limX y x
        | (limX == 1) || (limY == 1)  = True
        | (x == limX) && (y == (limY - 1))  = True
        | (x == limX)   = aux xs limY limX (y+1) 1
        | notElem (y,x) xs && notElem (y+1,x) xs && notElem(y,x+1) xs && notElem (y+1,x+1) xs = False
        | otherwise = aux xs limY limX y (x+1)
      
-- dike_expand dla danego punktu reprezentującego groble tworzy listę wszystkich innych pól reprezentujązych groble które są połączone z tym punktem
      
dike_expand::[(Int,Int)] -> [(Int,Int)] -> Int -> Int -> [(Int,Int)]
dike_expand xs path limY limX
    | (xout == xs)   = xs
    | otherwise = dike_expand xout path limY limX where
    xout = outline xs path limY limX ++ xs

-- jeżeli wynik funkcji dike_expand złożony z listą stawów ma długość równą wszystkim pól planszy wiemy że grobla jest spójna

connected_dike limY limX xs = ((length xs) + (length dike) == (limX * limY)) where
    dike = dike_expand [fd] xs limY limX
    fd = first_dike xs limY limX

-- funckcje pomocnicze dla funkcji zamieniającą listę współrzędnych na liste typu field
    
fh x y (a,b,_)
    | (x == a) && (y == b) = True
    | otherwise = False
   
thr:: Maybe (Int,Int,Int) -> Int  
thr mx = case mx of
    Nothing -> 0
    Just (_,_,c) -> c
   
display_row:: [(Int,Int,Int)] -> [(Int,Int)] -> Int -> Int -> Int -> [Field]
display_row ys xs n row limX
    | n > limX         = []
    | x /= 0     = N x:(display_row ys xs (n+1) row limX) 
    | elem (row, n) xs  = P:(display_row ys xs (n+1) row limX)
    | otherwise        = D:(display_row ys xs (n+1) row limX) where
    x = thr(find (fh row n) ys)

-- funkcja zwracajaca wynik poprawnego typu    

display_plane:: Int -> Int -> Int -> [(Int,Int,Int)] -> [(Int,Int)] -> [[Field]]
display_plane m limY limX ys xs
    | m > limY  = []
    | otherwise = (display_row ys xs 1 m limX):(display_plane (m+1) limY limX ys xs)

tests :: [Test]
tests = [SimpleTest (Puzzle 3 3 [(1,1,5), (3,3,1)]) [[N 5, P, P],[P, D, D],[P, D, N 1]],
 SimpleTest (Puzzle 5 5 [(1,1,1),(1,5,1),(5,1,1),(5,5,1),(3,3,5)]) [[N 1,D,D,D,N 1],[D,D,P,D,D],[D,P,N 5,P,D],[D,D,P,D,D],[N 1,D,D,D,N 1]],
 SimpleTest (Puzzle 5 5 [(3,3,7)]) [[D,D,D,D,D],[D,P,D,P,D],[D,P,N 7,P,D],[D,P,D,P,D],[D,D,D,D,D]],
 CountTest (Puzzle 5 5 [(3,3,1),(1,1,6),(5,5,6)]) 2]   
    
solve:: Solver
solve limY limX xs 
    | xs == [] && wide_dike limY limX [] && connected_dike limY limX [] = [display_plane 1 limY limX xs []]
    | otherwise = map (display_plane 1 limY limX xs) (filter (\pond -> (wide_dike limY limX pond)&&(connected_dike limY limX pond)) (gen_ponds xs [] limY limX))

main :: IO ()
main = checkerMain solve tests
