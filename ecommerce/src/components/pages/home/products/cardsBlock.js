import React, { useState } from "react";
import Popup from "./productPopup";
export const CardsBlock = ({ product, loading, currentProducts }) => {
  const [selectedProduct, setSelectedProduct] = useState(null);

  const openPopup = (product) => {
    setSelectedProduct(product);
  };

  const closePopup = () => {
    setSelectedProduct(null);
  };

  return (
    <div className="main-block">
      {loading ? (
        <p>Loading...</p>
      ) : currentProducts.length === 0 ? (
        <p>No products found.</p>
      ) : (
        currentProducts.map((product) => (
          <div
            key={product.id}
            className="card"
            onClick={() => openPopup(product)}
          >
            <img src={product.thumbnail} alt={product.title} />
            <h2>{product.title}</h2>
            <p>Price: ${product.price.toFixed(2)}</p>
            <p>Rating: {product.rating}</p>
          </div>
        ))
      )}

      {selectedProduct && (
        <Popup product={selectedProduct} onClose={closePopup} />
      )}
    </div>
  );
};
