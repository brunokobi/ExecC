package modelo;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;
import javax.servlet.ServletException;

/**
 *
 * @author Rômulo F. Douro <rfdouro at gmail.com>
 */
public class PessoaDAO {

    public void insere(Pessoa p) throws ServletException {
        Connection con = null;
        PreparedStatement st = null;
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            con
                    = DriverManager.getConnection("jdbc:mysql://localhost:3306/cadastro?useTimezone=true&serverTimezone=UTC", "root", "");
            con.setAutoCommit(false);
            st = con.prepareStatement("insert into pessoa(nome)values (?)");
            st.setString(1, p.getNome());
            st.executeUpdate();
            con.commit();
        } catch (Exception ex) {
            try {
                con.rollback();
            } catch (Exception sqlex) {
            }
            throw new ServletException(ex.getMessage());
        } finally {
            try {
                con.close();
            } catch (Exception sqlex) {
            }
        }
    }

    public void excluir(Pessoa p) throws ServletException {
        Connection con = null;
        PreparedStatement st = null;
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            con
                    = DriverManager.getConnection("jdbc:mysql://localhost:3306/cadastro?useTimezone=true&serverTimezone=UTC", "root", "");
            con.setAutoCommit(false);
            st = con.prepareStatement("delete from pessoa where id =? ");
            st.setLong(1, p.getId());
            st.executeUpdate();
            con.commit();
        } catch (Exception ex) {
            try {
                con.rollback();
            } catch (Exception sqlex) {
            }
            throw new ServletException(ex.getMessage());
        } finally {
            try {
                con.close();
            } catch (Exception sqlex) {
            }
        }
    }

    public List<Pessoa> lista() throws ServletException {
        List<Pessoa> l = null;
        Connection con = null;
        PreparedStatement st = null;
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            con
                    = DriverManager.getConnection("jdbc:mysql://localhost:3306/cadastro?useTimezone=true&serverTimezone=UTC ", "root", "");
            st = con.prepareStatement("select * from pessoa order by nome");
            ResultSet rs = st.executeQuery();
            l = new ArrayList<>();
            while (rs.next()) {
                Pessoa p = new Pessoa();
                p.setId(rs.getLong("id"));
                p.setNome(rs.getString("nome"));
                l.add(p);
            }
        } catch (Exception ex) {
            throw new ServletException(ex.getMessage());
        } finally {
            try {
                con.close();
            } catch (Exception sqlex) {
            }
        }
        return l;
    }
    
    public Pessoa seleciona(Long id) throws ServletException {
        Pessoa p = null;
        Connection con = null;
        PreparedStatement st = null;
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            con
                    = DriverManager.getConnection("jdbc:mysql://localhost:3306/cadastro?useTimezone=true&serverTimezone=UTC ", "root", "");
            st = con.prepareStatement("select * from pessoa where id =? ");
            st.setLong(1, id);
            ResultSet rs = st.executeQuery();
            if (rs.next()) {
                p = new Pessoa();
                p.setId(rs.getLong("id"));
                p.setNome(rs.getString("nome"));
            }
        } catch (Exception ex) {
            throw new ServletException(ex.getMessage());
        } finally {
            try {
                con.close();
            } catch (Exception sqlex) {
            }
        }
        return p;
    }
    
     public void alterar(Pessoa p) throws ServletException {
        Connection con = null;
        PreparedStatement st = null;
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            con
                    = DriverManager.getConnection("jdbc:mysql://localhost:3306/cadastro?useTimezone=true&serverTimezone=UTC", "root", "");
            con.setAutoCommit(false);
            st = con.prepareStatement("update pessoa set nome=?  where id =? ");
            st.setString(1, p.getNome());
            st.setLong(2, p.getId());
            st.executeUpdate();
            con.commit();
        } catch (Exception ex) {
            try {
                con.rollback();
            } catch (Exception sqlex) {
            }
            throw new ServletException(ex.getMessage());
        } finally {
            try {
                con.close();
            } catch (Exception sqlex) {
            }
        }
    }
}
