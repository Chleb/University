-- ----------------------------------------------------------------------------
-- Puzzle.hs
-- WERSJA 0.2
-- ZADANIE 4 (Stawy i grobla)
-- ----------------------------------------------------------------------------
module Puzzle where

data Field = D | P | N Int deriving Eq

data Puzzle = Puzzle Int Int [(Int, Int, Int)]
type Result = [[Field]]
type Solver = Int -> Int -> [(Int, Int, Int)] -> [Result]

data Test
    = SimpleTest Puzzle Result
    | CountTest  Puzzle Int

    
runSolver :: Solver -> Puzzle -> [Result]
runSolver solver (Puzzle m n l) = solver m n l


checkSolution :: Result -> Result -> Bool
checkSolution = ( == )


baseTests :: [Test]
baseTests = [(SimpleTest (Puzzle 3 3 [(1,1,3), (3,3,3)])
 [[N 3, D, P],[P, D, P],[P, D, N 3]]),
 (SimpleTest (Puzzle 5 5 [(1,1,1), (3,1,1), (5,1,1), (2,3,1), (4,3,1), (1,5,1), (3,5,1), (5,5,1)])
 [[N 1, D, D, D, N 1],[D, D, N 1, D, D],[N 1, D, D, D, N 1],[D, D, N 1, D, D],[N 1, D, D, D, N 1]]),
 SimpleTest (Puzzle 7 7 [(1,2,1), (3,1,2), (3,5,3), (3,7,3), (4,4,1), (5,5,2), (7,1,4), (7,3,3), (7,7,2)])
 [[D, N 1, D, D, D, D, P],[D, D, D, P, P, D, P],[N 2, P, D, D, N 3, D, N 3],[D, D, D, N 1, D, D, D],[P, P, D, D, N 2, P, D],[P, D, D, P, D, D, D],[N 4, D, N 3, P, D, P, N 2]],
  CountTest (Puzzle 3 3 [(1,1,3), (3,3,3)]) 2,
  CountTest (Puzzle 7 7 [(1,2,1), (3,1,2), (3,5,3), (3,7,3), (4,4,1), (5,5,2), (7,1,4), (7,3,3), (7,7,2)]) 1]