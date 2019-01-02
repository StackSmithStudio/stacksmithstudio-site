import HomeIcon from 'react-feather/dist/icons/home';
import FolderIcon from 'react-feather/dist/icons/folder';
import InfoIcon from 'react-feather/dist/icons/info';
import BlogIcon from 'react-feather/dist/icons/book';

const menu = [
  { label: 'Home', to: '/#', icon: HomeIcon },
  { label: 'About', to: '/#about', icon: InfoIcon },
  { label: 'Projects', to: '/#projects', icon: InfoIcon },
  { label: 'Contact', to: '/#contact', icon: BlogIcon },
  { label: 'Resume', to: '/resume', icon: FolderIcon },
  // { label: 'Catalog', to: '/catalog', icon: FolderIcon },
  
];

export default menu;
