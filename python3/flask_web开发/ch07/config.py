import os

BASE_DIR = os.path.abspath(os.path.dirname(__file__))


class Config:
    SECRET_KEY = os.environ.get("secret_key")
    MAIL_SERVER = os.environ.get("mail_server", "smtp.qq.com")
    MAIL_PORT = int(os.environ.get("mail_port", "587"))
    MAIL_USE_TLS = os.environ.get("mail_use_tls", "true").lower() in ("true", "on", "1")
    MAIL_USERNAME = os.environ.get("mail_user")
    MAIL_PASSWORD = os.environ.get("mail_pass")
    SQLALCHEMY_TRACK_MODIFICATIONS = False

    @staticmethod
    def init_app(app):
        pass


class DevelopmentConfig(Config):
    """开发环境配置"""
    DEBUG = True
    SQLALCHMY_DATABASE_URI = os.environ.get("dev_database_url") or "sqlite:///" + os.path.join(BASE_DIR, "data-dev.sqlite")


class TestingConfig(Config):
    """测试环境配置"""
    TESTING = True
    SQLALCHEMY_DATABASE_URI = os.environ.get("test_database_url") or "sqlite://"


class ProductionConfig(Config):
    """生产环境配置"""
    SQLALCHEMY_DATABASE_URI = os.environ.get("database_url") or "sqlite:///" + os.path.join(BASE_DIR, "data.sqlite")


CONFIG = {
    "development": DevelopmentConfig,
    "testing": TestingConfig,
    "production": ProductionConfig,

    "default": DevelopmentConfig
}
