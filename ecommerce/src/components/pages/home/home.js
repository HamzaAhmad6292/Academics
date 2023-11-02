import React, { useState, useEffect } from "react";
import axios from "axios";
import { useSelector } from "react-redux";
import { Pagination } from "../../../utils/pagination";
import { Sidebar } from "./sidebar/sidebar";
import { Navbar } from "../navbar/navbar";
import { CardsBlock } from "./products/cardsBlock";
import { baseUrl } from "../../../utils/api";
export const Home = () => {
  // State variables
  const [products, setProducts] = useState([]);
  const [loading, setLoading] = useState(true);
  const [currentPage, setCurrentPage] = useState(1);
  const [productsPerPage] = useState(12);

  // Get selectedCategory and searchQuery from Redux store
  const selectedCategory = useSelector((state) => state.selectedCategory);
  const searchQuery = useSelector((state) => state.searchQuery);

  // Effect to scroll to the top when currentPage changes
  useEffect(() => {
    window.scrollTo({ top: 0, behavior: "smooth" });
  }, [currentPage]);

  useEffect(() => {
    setCurrentPage(1);
    const queryParams = searchQuery ? `?search=${searchQuery}` : "";
    const searchUrl = selectedCategory
      ? `${baseUrl}/category/${selectedCategory}`
      : `${baseUrl}`;

    axios
      .get(searchUrl)
      .then(function (response) {
        const fetchedProducts = response.data.products;
        const filteredProducts = searchQuery
          ? fetchedProducts.filter((product) =>
              product.title.toLowerCase().includes(searchQuery.toLowerCase())
            )
          : fetchedProducts;
        setProducts(filteredProducts);
        setLoading(false);
      })

      .catch(function (error) {
        console.log(error);
        // Handle error
        console.error("Error fetching data:", error);
        setLoading(false);
      });
  }, [searchQuery, selectedCategory]);

  // Get current products for the current page
  const indexOfLastProduct = currentPage * productsPerPage;
  const indexOfFirstProduct = indexOfLastProduct - productsPerPage;
  const currentProducts = products.slice(
    indexOfFirstProduct,
    indexOfLastProduct
  );

  // Function to change the current page
  const paginate = (pageNumber) => setCurrentPage(pageNumber);

  return (
    <div className="">
      {/* //navbar */}
      <div className="">
        <Navbar></Navbar>
      </div>
      <div className="main-container">
        <Sidebar />
        <CardsBlock
          currentProducts={currentProducts}
          loading={loading}
        ></CardsBlock>
      </div>
      <Pagination
        itemsPerPage={productsPerPage}
        totalItems={products.length}
        currentPage={currentPage}
        paginate={paginate}
      />
      <div className="footer"></div>
    </div>
  );
};
