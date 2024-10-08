from hoagie_italiano import HoagieItaliano
from hoagie_vegano import HoagieVegano


if __name__ == "__main__":
    print("sanduba italiano")
    sanduba_italiano = HoagieItaliano()
    sanduba_italiano.fazer_sanduba()

    print("\n\nsanduba vegano")
    sanduba_vegano = HoagieVegano()
    sanduba_vegano.fazer_sanduba()
