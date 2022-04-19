import React, { Component } from "react";
import ReactFacebookLogin from "react-facebook-login";
import styles from "./facebookButton.module.css"

export default class Facebook extends Component {
  // Изначально делаем что пользователь не залогинен
  state = {
    isLoggedIn: false,
    userID: "",
    name: "",
    email: "",
    picture: "",
  };
  // JSON ответ
  responseFacebook = (response) => {
    console.log(response);
    
    this.setState({
      isLoggedIn: true,
      userID: response.userID,
      name: response.name,
      email: response.email,
      picture: response.picture.data.url,
    });
  };

  componentClicked = () => console.log("clicked");

  render() {
    let fbContent;
    
    if (this.state.isLoggedIn) {
      // Здесь используем json данные
      fbContent = null;
    } else 
    // Если не залогинены появляется кнопка
    { 
      fbContent = (
        <ReactFacebookLogin
          appId="1126095331293311"
          autoLoad={false}
          size="small"
          cssClass={styles.facebookButton}
          fields="name,email,picture"
          onClick={this.componentClicked}
          callback={this.responseFacebook}
        />
      );
    }

    return <div >{fbContent}</div>;
  }
}
