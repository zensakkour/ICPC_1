from enum import Enum


class Color(Enum):
    WHITE = "white"
    BLACK = "black"


class Piece:
    def __init__(self, color: Color):
        self.color = color

    def is_valid_move(self, fxy : Tuple[int,int], roxy : Tuple[int,int], board) -> bool:


class Knight(Piece):

    def symbol(self)-> str:
        return "N"
    
    def is_valid_move(self, fxy, toxy, board):
        fx,fy = fxy
        tx, ty = toxy
        dx = abs(tx- fx)
        dy = abs(ty - fy)

        if (dx,dy) not in {(2,1), (1,2)}:
            return False

        occu = board.piece_at(tx,ty)
        return occu is None or occu.color is not self.color
class Bishop(Piece):
    #symbol

    def is_valid_move(self, fxy, toxy, board):
        fx,fy = fxy
        tx, ty = toxy
        dx = tx- fx
        dy = ty - fy

        if abs(dx) != abs(dy) or dx == 0:
            return False
        
        stepx = 1 if dx >0 else -1
        stepy = 1 if dy >0 else -1

        cx, cy = fx + stepx, fy + stepy
        while(cx, cy) != (tx,ty):
            if board.piece_at(cx,cy) is not None:
                return False
            
            cx += stepx
            cy += stepy
        
        occu = board.piece_at(tx,ty)
        return occu is None or occu.color is not self.color



    
class board:

    # piece at  None is bas
    # in_bound

    def remove_piece(self, piece :Piece, x :int, y : int) -> None:
        if not self.in_bound(x,y):
            #error
        
        self.grid[x][y] = None

    def move_p(self, fxy : Tuple[int,int], toxy : Tuple[int,int]):
        fx,fy = fxy
        tx, ty = toxy

        # in bound chek

        mover = self.grid[fx,fy]
        capt = self.grid[tx,ty]
        if 
        self.grid[fx,fy] = None
        self.grid[tx,ty] = mover

        return capt
                
class Game :
    def __init__():
        self.board= Board()
        self.piece_count = {Color.WHITE : 0, Color.BLACK :0}


    
    def is_valid_move(self, fx: int, fy: int, tx : int, ty : int):
        piece = self.board.piece_at(fx,fy)
        return piece.is_valid_move((fx,fy), (tx,ty), self.board)
    
    def move(self, fx: int, fy: int, tx : int, ty : int):
        # if not self.is_valid_move()

        piece = self.boardpiece_at(fx,fy)
        capt = self.boardpiece_at(tx,ty)


    