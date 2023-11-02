import axios from "axios";
import { useState, useEffect } from "react";
import { useDispatch, useSelector } from "react-redux";
import { setSelectedCategory } from "../../../../Redux/actions";
import { baseUrl } from "../../../../utils/api";
export const Categories = () => {
  const [allCategories, setAllCategories] = useState([]);
  const dispatch = useDispatch();
  const selectedCategory = useSelector((state) => state.selectedCategory);

  useEffect(() => {
    axios
      .get(baseUrl + "/categories")
      .then(function (response) {
        setAllCategories(response.data);
      })
      .catch(function (error) {
        console.log(error);
      });
  }, []);

  const onClickCategory = (e) => {
    const category = e.target.textContent;
    dispatch(setSelectedCategory(category));
  };

  return (
    <div className="category-container">
      {/* the div under this indication for chatgpt */}
      {allCategories.map((category) => (
        <button
          key={category}
          className={`category-button ${
            selectedCategory === category ? "active" : ""
          }`}
          onClick={onClickCategory}
        >
          {category}
        </button>
      ))}
    </div>
  );
};
