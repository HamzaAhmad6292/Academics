import React from "react";
import IconButton from "@mui/material/IconButton";
import MenuIcon from "@mui/icons-material/Menu";

const DrawerButton = ({ onDrawerOpen }) => {
  return (
    <IconButton
      size="large"
      edge="start"
      color="inherit"
      aria-label="open drawer"
      onClick={onDrawerOpen}
    >
      <MenuIcon />
    </IconButton>
  );
};

export default DrawerButton;
