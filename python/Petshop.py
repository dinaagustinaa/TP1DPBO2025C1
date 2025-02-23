# petshop.py
class Petshop:
    def __init__(self, id="", name="", category="", price=0.0):
        self.id = id
        self.name = name
        self.category = category
        self.price = price
    
    # Setter dan Getter ID
    def set_id_product(self, id):
        self.id = id
    
    def get_id_product(self):
        return self.id
    
    # Setter dan Getter Name
    def set_name_product(self, name):
        self.name = name
    
    def get_name_product(self):
        return self.name
    
    # Setter dan Getter Category
    def set_category_product(self, category):
        self.category = category
    
    def get_category_product(self):
        return self.category
    
    # Setter dan Getter Price
    def set_price_product(self, price):
        self.price = price
    
    def get_price_product(self):
        return self.price
