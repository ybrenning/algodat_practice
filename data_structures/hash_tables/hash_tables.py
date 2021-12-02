# Python implements hash tables using the dictionary data type (dicts).

if __name__ == "__main__":
    phone_book = {}
    phone_book["ross"] = 8675309
    phone_book["rachel"] = 893201
    phone_book["emergency"] = 911

    print(phone_book)
    print(phone_book.keys())
    print(phone_book.values())
    print(phone_book.items())
    print(phone_book.get("ross"))
    print(phone_book["ross"])

# Short recap on hash tables:
# - Generally speaking, they consist of a hash function and an array
# - Hash tables have quick insert, access and delete operations
# - They are useful for modelling relationships from one item to another item
# - Collisions should always be avoided as much as possible -> choice of hash function
