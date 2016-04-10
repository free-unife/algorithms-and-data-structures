import random

# generate many integers between -100 and 100
def generate_random_integers( many ):
    
    random_integers = []
    
    for i in range( 0, many ):
        random_number = random.randint( -100, 100 )
        random_integers.append( random_number )
    
    return random_integers

# check if an entered vector is asc_ordered or not
def is_asc_ordered( input_array ):
    
    for i in range( 0, len( input_array ) - 2):
        if input_array[i] > input_array[i + 1]:
            return False
    return True
