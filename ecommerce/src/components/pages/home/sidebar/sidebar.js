import React from "react";
import { Categories } from "./catagories.js";
import { useDispatch } from "react-redux";
import { setSelectedCategory } from "../../../../Redux/actions.js";
import { useSelector } from "react-redux";

export const Sidebar = () => {
  const drawer = useSelector((state) => state.drawer);
  const dispatch = useDispatch();

  const onclickRestCategory = () => {
    dispatch(setSelectedCategory(null));
  };

  if (!drawer) {
    return null; // Don't render the sidebar if drawer is false
  }

  return (
    <div className="sidebar">
      <button onClick={onclickRestCategory} className="clear-filters-button">
        Clear filter
      </button>
      <div>
        <Categories></Categories>
      </div>
    </div>
  );
};
