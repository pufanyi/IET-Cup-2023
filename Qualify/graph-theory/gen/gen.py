import random
import typing

def random_tree(n: int) -> typing.List[typing.Tuple[int, int, int]]:
    """Generate a random tree with n vertices

    Args:
        n (int): The number of vertices

    Returns:
        typing.List[typing.Tuple[int, int]]: The list of edges
    """
    MAX_EDGE_WEIGHT = 1000000
    edges = []
    for i in range(2, n + 1):
        edges.append((random.randint(1, i - 1), i, random.randint(1, MAX_EDGE_WEIGHT)))
    return edges
