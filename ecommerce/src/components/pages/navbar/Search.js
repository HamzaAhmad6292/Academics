import React, { useState } from "react";
import { useDispatch } from "react-redux";
import { setSearchQuery } from "../../../Redux/actions";
import TextField from "@mui/material/TextField";

export const Search = () => {
  const [productTitle, setProductTitle] = useState("");
  const dispatch = useDispatch();

  const onSearchHandler = () => {
    dispatch(setSearchQuery(productTitle));
  };

  const searchUpdate = (e) => {
    setProductTitle(e.target.value);
  };

  const handleKey = (e) => {
    if (e.code === "Enter") {
      onSearchHandler();
    }
  };

  return (
    <div className="search-container">
      <div className="search-icon-wrapper">{/* Search Icon Here */}</div>
      <TextField
        className="input-base"
        type="text"
        label="Search"
        placeholder="Search"
        variant="outlined"
        onChange={searchUpdate}
        onKeyDown={handleKey}
      />
      {/* <Button
        className="search-button"
        variant="contained"
        color="primary"
        onClick={onSearchHandler}
      >
        Search
      </Button> */}
    </div>
  );
};
