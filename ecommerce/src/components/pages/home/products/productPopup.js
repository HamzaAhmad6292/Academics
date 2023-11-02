import React from "react";

const Popup = ({ product, onClose }) => {
  return (
    <div className="popup-container" onClick={onClose}>
      <div className="popup">
        <div className="popup-image">
          <img src={product.thumbnail} alt={product.title} />
        </div>
        <div className="popup-content">
          <h2>{product.title}</h2>
          <p className="description">{product.description}</p>
          <p className="price">
            Price: ${product.price.toFixed(2)}{" "}
            <span className="discount">
              ({product.discountPercentage}% off)
            </span>
          </p>
          <p>Rating: {product.rating}</p>
          <p>Brand: {product.brand}</p>
          <p>Category: {product.category}</p>
          <button className="buy-button" onClick={(e) => e.stopPropagation()}>
            Buy Now
          </button>
        </div>
      </div>
    </div>
  );
};

export default Popup;
