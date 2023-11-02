import React, { useState } from "react";
import AppBar from "@mui/material/AppBar";
import Toolbar from "@mui/material/Toolbar";
import Typography from "@mui/material/Typography";
import { Search } from "./Search";
import DrawerButton from "./drawer";
import { useDispatch } from "react-redux";
import { useSelector } from "react-redux";
import { setDrawer } from "../../../Redux/actions";

export const Navbar = () => {
  const drawer = useSelector((state) => state.drawer);

  const dispatch = useDispatch();
  const [isDrawerOpen, setIsDrawerOpen] = useState(false);

  const handleDrawerOpen = () => {
    dispatch(setDrawer(!drawer));
  };

  const navbarStyles = `
    .navbar {
      width: 100%;
    }

    .app-bar {
      background-color: white; /* Updated background color */
      color: #2196f3; /* Updated text color */
    }

    .toolbar {
      display: flex;
      align-items: center;
      padding: 0 16px;
    }

    .title {
      flex-grow: 1;
      font-size: 1rem;
    }
  `;

  return (
    <div className="navbar">
      <style>{navbarStyles}</style>
      <AppBar position="static">
        <Toolbar style={navbarStyles.toolbar} className="app-bar">
          <DrawerButton onDrawerOpen={handleDrawerOpen} />
          <Typography className="title" variant="h6" noWrap>
            E-Mart
          </Typography>
          <Search />
        </Toolbar>
      </AppBar>
      {/* Render Drawer component here based on isDrawerOpen */}
    </div>
  );
};
