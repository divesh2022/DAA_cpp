def print_solution(board):
    for row in board:
        print(" ".join("Q" if col else "." for col in row))
    print("\n")

def is_safe(board, row, col, n):
    for i in range(col):
        if board[row][i]:
            return False
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j]:
            return False
    for i, j in zip(range(row, n), range(col, -1, -1)):
        if board[i][j]:
            return False
    return True

def solve_n_queens_util(board, col, n, count):
    if col >= n:
        print_solution(board)
        count[0] += 1
        return True
    res = False
    for i in range(n):
        if is_safe(board, i, col, n):
            board[i][col] = 1
            res = solve_n_queens_util(board, col + 1, n, count) or res
            board[i][col] = 0
    return res

def solve_n_queens(n):
    board = [[0 for _ in range(n)] for _ in range(n)]
    count = [0]
    if not solve_n_queens_util(board, 0, n, count):
        print("No solution exists")
    else:
        print(f"Total solutions found: {count[0]}")

if __name__ == "__main__":
    t = int(input("enter no of test cases : "))
    for _ in range(t):
        n = int(input("enter the number of queens : "))
        solve_n_queens(n)
        print("\n")
