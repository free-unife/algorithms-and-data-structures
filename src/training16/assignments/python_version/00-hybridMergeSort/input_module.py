import random

class InputObject(object):
    def __init__( self , input_array = [] ):
        self.input_array = input_array
        return

    def generate_random_integers( self, many ):
        for i in range( 0, many ):
            random_number = random.randint( -100, 100 )
            self.input_array.append( random_number )
        return self.input_array

    def is_asc_ordered( self ):
        for i in range(0, len( self.input_array ) - 2):
            if self.input_array[i] > self.input_array[i + 1]:
                return False
        return True
