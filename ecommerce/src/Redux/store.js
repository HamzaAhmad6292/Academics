import { configureStore } from "@reduxjs/toolkit";

const initialState = {
  searchQuery: "",
  selectedCategory: null,
  setDrawer: false,
};

const rootReducer = (state = initialState, action) => {
  switch (action.type) {
    case "SET_SEARCH_QUERY":
      return { ...state, searchQuery: action.payload };
    case "SET_SELECTED_CATEGORY":
      return { ...state, selectedCategory: action.payload };
    case "SET_DRAWER":
      return { ...state, drawer: action.payload };
    default:
      return "";
  }
};

export const Store = configureStore({
  reducer: rootReducer,
});
